// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_valid_create(string skillname);
int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        int skill, skill_basic;
string arg2,arg3,arg4,arg5;
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0;
                string mission, wname, wmin, file,mission2;
        string *wmission,pfm,fz1,fz2,fz3;
        
        object ob;
        
        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( !arg )
                return notify_fail("ָ���ʽ��selfpf <�书> <����> <����> <����>\n");



if(!sscanf(arg, "%s %s %s %s", arg2, arg3,arg4,arg5)) 
return notify_fail("ָ���ʽ��selfpf <�书> <����> <����> <����>\n");

        if(check_valid_create(arg2)==0)
                return notify_fail("�ⲻ���㴴���Ĺ���ѽ��\n");


if(CHINESE_D->check_length(arg5) > 160)
{
return notify_fail("����̫��!\n");
}

if(CHINESE_D->check_control(arg5))
{
return notify_fail("��������ȷ!\n");
}

if (arg3!="dan" && arg3!="hun" && arg3!="lian")
return notify_fail("���಻��ȷ! ����Ϊdan hun lian  ����\n");

if (arg4!="����" && arg4!="����" && arg4!="����" && arg4!="δ��")
return notify_fail("���಻��ȷ! ����Ϊ���� ���� ���� δ�� ����\n");

if((int)me->query("combat_exp") < 5000000)
       return notify_fail("��ľ���ֵ��������\n");

if (arg4=="����")
me->add("combat_exp",-2000000);


        seteuid(getuid());
        filen = "/p/skill/"+arg2+arg3;
        if (!read_file(filen))  write_file(filen, "���� ��\n���� ��\n���� ��\nδ�� ��", 1);
        wmission = explode(read_file(filen), "\n");
mission="";
for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wmin,wname)!=2 ) continue;
        if (wmin=="����")        pfm=wname;
        if (wmin=="����")        fz1=wname;
        if (wmin=="����")        fz2=wname;
        if (wmin=="δ��")        fz3=wname;

if (wmin==arg4) mission+=wmin+" "+arg5+"\n";
else mission+=wmin+" "+wname+"\n";
        }

      write_file(filen, mission, 1);
      //write_file(filen, "", 1);  
        if (arg4=="����")
        message_vision("�㾭����˼ڤ�� ���ڴ�����һ�ž�ѧ\n"+mission+"�ɹ���\n", me, ob);
		tell_object (me,mission);


return 1;                   
//if (1==1)                
         //return notify_fail("��"+pfm+"��"+fz1+"��"+fz2+"��"+arg2+"��"+check_valid_create(arg2)+"��"+filen+"��"+fz3+"����ѽ��\n");       
}

int check_valid_create(string skillname)
{
string file,*list,playername;
object me;

me=this_player();
file=read_file(SKILL_D(skillname+".c"));
if(!file) 
     return 0;
list = explode(file, "\n");
playername=geteuid(me);

if(list[1]!="// "+playername)
      return 0;
if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
           return 0;

return 1;
}


int help(object me)
{
        write(@TEXT
ָ���ʽ��selfpf <����> <����> <����>

���ָ��������ϰĳ���Լ������ļ��ܵľ��� ÿ����һ�л��޸���������Ҫ�������2M����
�书Ϊ���Դ��书��ID
����Ϊdan hun lian  ���� dan(����) hun (���) lian(����)
����Ϊ���� ���� ���� δ�� ����
�����в��ܳ��ֿ��Ʒ�����Ȼ��ɾ��!
������ �� �� С��� ����������˵�����
����:������һԾ��һ�С����к�ء���׼С���бб�̳�һ��
���磺selfpf mytest-unarmed dan ���� ��һ��
      selfpf mytest-unarmed dan ���� ������һԾ��һ�С����к�ء���׼С���бб�̳�һ��

TEXT
        );
        return 1;
}

