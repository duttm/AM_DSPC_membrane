
function [varargout] = MI(varargin)
%MI('dump_19.txt')
try
    %dump = fopen(varargin{1},'r');
    dump = fopen('dump_19.txt','r');
catch
    error('Dumpfile not found!');
end

p=1;

while feof(dump) == 0
    id = fgetl(dump);
    switch id
        case 'time'
            steps(p) = str2num(fgetl(dump));
            
        case 'AM_num'
            clust_num(p) = str2num(fgetl(dump));
        case 'data'
            for j = 1 : 1: 110*clust_num(p)
                atom_data(j,:) = str2num(fgetl(dump));
                atom(j,p) =atom_data(j,1);
                mol(j,p) =atom_data(j,2);
                type(j,p) =atom_data(j,3);
                x(j,p) = atom_data(j,4);
                y(j,p) = atom_data(j,5);
                z(j,p) = atom_data(j,6);
                
            end
            p=p+1;
    end
end


for t=1:length(steps)
    for clust=1:clust_num(t)
        x_com=0;
        y_com=0;
        z_com=0;
		clust_size(t,clust)=110;
        for cap=1:110%find com wrt 1st cap in cluster
            x_com=x_com+x(110*(clust-1)+cap,t);
            y_com=y_com+y(110*(clust-1)+cap,t);
            z_com=z_com+y(110*(clust-1)+cap,t);
        end
        %change com back to original axes
        x_com=(x_com/110);
        y_com=(y_com/110);
        z_com=(z_com/110);
        %ensure com stays in bounds
        
        S=[1 1 1; 1 1 1; 1 1 1];%create tensor
        for cap=1:110
            S(1,1)=S(1,1)+(x(110*(clust-1)+cap,t)-x_com)^2;
            S(1,2)=S(1,2)+(x(110*(clust-1)+cap,t)-x_com)*(y(110*(clust-1)+cap,t)-y_com);
            S(1,3)=S(1,3)+(x(110*(clust-1)+cap,t)-x_com)*(z(110*(clust-1)+cap,t)-z_com);
            S(2,1)=S(2,1)+(x(110*(clust-1)+cap,t)-x_com)*(y(110*(clust-1)+cap,t)-y_com);
            S(2,2)=S(2,2)+(y(110*(clust-1)+cap,t)-y_com)^2;
            S(2,3)=S(2,3)+(y(110*(clust-1)+cap,t)-y_com)*(z(110*(clust-1)+cap,t)-z_com);
            S(3,1)=S(3,1)+(x(110*(clust-1)+cap,t)-x_com)*(z(110*(clust-1)+cap,t)-z_com);
            S(3,2)=S(3,2)+(y(110*(clust-1)+cap,t)-y_com)*(z(110*(clust-1)+cap,t)-z_com);
            S(3,3)=S(3,3)+(z(110*(clust-1)+cap,t)-z_com)^2;
        end
        
        Sforrog=S./110;
        rog(t,clust)=sum(eig(Sforrog))^.5;
        
        Seig=eig(S);
        lambda_x(t,clust)=Seig(1); %Finding the lambda values explicitely
        lambda_y(t,clust)=Seig(2);
        lambda_z(t,clust)=Seig(3);
        %order lambdas into high, medium, and lowest
        a=[lambda_x(t,clust),lambda_y(t,clust), lambda_z(t,clust)];
        lambda_high(t,clust)=max(a);
        lambda_low(t,clust)=min(a);
        lambda_med(t,clust)=sum(a)-max(a)-min(a);
    end
end

%Find maximum clust_size
%Use max indices to find lambda and ROG of it
for t=1:length(steps)
    clust_sizemax(t)=max(clust_size(t,:)); %maximum cluster size matrix
    B=find(clust_size(t,:)==max(clust_size(t,:)));  %index of the maximum cluster sizes in a time step
    
    rogmaxES=rog(t,B); %all of the rog's of the maximum clusters in a time step
        avgrogES=sum(rogmaxES)/length(B); %average the rog's from those clusters in above line
        rogmax(t)=avgrogES; %place that average rog into the maxrog matrix. this is the only one that saves for each line because its column size stays the same
    
    lambdamaxES_high=lambda_high(t,B); %repeat above process for the lambdaS
        avglambdahighES=sum(lambdamaxES_high)/length(B);
        lambdamax_high(t)=avglambdahighES;
        
    lambdamaxES_low=lambda_low(t,B);
        avglambdalowES=sum(lambdamaxES_low)/length(B);
        lambdamax_low(t)=avglambdalowES;
        
    lambdamaxES_med=lambda_med(t,B);
        avglambdamedES=sum(lambdamaxES_med)/length(B);
        lambdamax_med(t)=avglambdamedES;
end

%this is where we time average all of the "maximum" matrices
avgrog=sum(rogmax)/length(steps);
stdrog=std(rogmax);

avgclustsize=sum(clust_sizemax)/length(steps);
stdclustsize=std(clust_sizemax);

avglambda_high=sum(lambdamax_high)/length(steps);
avglambda_low=sum(lambdamax_low)/length(steps);
avglambda_med=sum(lambdamax_med)/length(steps);

stdlambda_high=std(lambdamax_high);
stdlambda_med=std(lambdamax_med);
stdlambda_low=std(lambdamax_low);

%Aspect Ratio of lambda^2
%Ar=dmin/dmax4
save = fopen('MI.txt','w');

for i=1:length(lambdamax_high)
    if (lambdamax_high > 0)
        Asp_high=(lambdamax_high)./(lambdamax_high);
        Asp_low=(lambdamax_low)./(lambdamax_high);
        Asp_med=(lambdamax_med)./(lambdamax_high);
        
    else
        Asp_high = 0;
        Asp_low = 0;
        Asp_med = 0;
    end
    avgAsp_high=sum(Asp_high)/length(steps);
    avgAsp_low=sum(Asp_low)/length(steps);
    avgAsp_med=sum(Asp_med)/length(steps);
	
    
    stdAsp_high=std(Asp_high);
    stdAsp_low=std(Asp_low);
    stdAsp_med=std(Asp_med);
	fprintf(save,'%0.4f %0.4f %0.4f %0.4f %0.4f %0.4f\n',avgAsp_high,stdAsp_high,avgAsp_low,stdAsp_low,avgAsp_med,stdAsp_med);
end
fclose(save);
fclose(dump);
