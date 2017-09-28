
function [varargout] = thickness(varargin)
%MI('dump_19.txt')
try
    %dump = fopen(varargin{1},'r');
    dump = fopen('dump_18.txt','r');
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
            for j = 1 : 1: 120
                atom_data(j,:) = str2num(fgetl(dump));
                axis(j,p) =atom_data(j,1);
                num(j,p) =atom_data(j,2);
                total(p) =atom_data(j,3);                           
            end
            p=p+1;
    end
end

for i=1:120
totalnum(i)=0;
end

save = fopen('avethickness.txt','w');
tnum=sum(total);

for i=1:120
    for j=1:(p-1)
    totalnum(i)=num(i,j)+totalnum(i);
    percent(i)=totalnum(i)/tnum;
    	
    end
    fprintf(save,'%0.4f %0.4f %0.4f\n',axis(i,1),totalnum(i),percent(i));
end
fclose(save);
fclose(dump);
