
#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2,isdest=0;
        object *inv;
        object ob;
        string mission, wname, wmin, file,mission2;
        string *wmission;
        if( me!=this_player(1) ) return 0;
        //if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
        //        return notify_fail("��ֻ�ܸı䵱ǰʹ���ߵ�����\n");
        //mission = replace_color( mission, 1);
    if(me->is_busy())
        return notify_fail("��������æ��\n");

 // if (!wizardp(me))
 // 	return notify_fail("û�ж���ҿ��ţ�\n"); 

        seteuid(getuid());
        filen = "/p/residence/banding/"+me->query("id");
        if (!read_file(filen))  write_file(filen, "", 1);
        wmission = explode(read_file(filen), "\n");


        if( !arg )
{
	if (!me->is_busy())
{
	        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
if (strlen(wname)==1)
        printf(HIG"���:"HIR+wname+HIG" ��ǰ��װ��:"NOR);
else    printf(HIG"���:"HIR+wname+HIG"��ǰ��װ��:"NOR);     
         if (newob=load_object(wmin))
        {
        printf(newob->query("name"));
      }
        printf("\n");
        }
}
me->start_busy(1);
                return notify_fail("��ȡװ��ָ���ʽ��bweapon <λ��1-50> \n");
}


if(!sscanf(arg, "%d %s", arg2, mission2)) 
return notify_fail("ָ���ʽ��bangding <1-50> (��������)\n");

        if(sscanf(arg, "%d %s", arg2, mission2)) 
{

        if(arg2<=0 || arg2>50)
            return notify_fail("�����λ������, ָ���ʽ��bangding <λ��1-50> (��������)\n");

}


        //j=0;
me->start_busy(3);
        
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
                //j=j+1;
                if( wname==arg ) {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
newob=load_object(wmin);
	if (newob)
	inv = all_inventory(me);
oldob=present(newob->query("id"),me);
if (oldob)
{
		for(i=0; i<sizeof(inv); i++)
if (base_name(inv[i])==wmin)
{
me->set_temp("isnbwp",1);
message_vision(HIG "$N˫��һ�� һ"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIG" ��ʧ��������С�\n" NOR, me);
isdest=1;
//if (inv[i]->query("bowner")==me->query("id"))
//{
	 destruct(inv[i]);
//}
}
}

if (isdest==0)
{
message_vision(HIR "$N˫��һչ һ"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" ������г�����$N���ϡ�\n" NOR, me);
me->set_temp("isnbwp",1);
newob=new(wmin);
newob->move(me);
newob->delete("equipped");
newob->set("bowner",me->query("id"));
//newob->set("name",newob->query("equipped"));
newob->set("equipped",0);
}

me->start_busy(3);
//                message_vision("$N��λ��"+wname+"ȡ��װ��: " + wmin + " ��\n", me, ob);
                        flag = 1;
                        break;
                }
        }
if (flag==0) return notify_fail("�����װ��λ�� (��λ���ް�װ��) \n");
        
        return 1;
}
        


int help(object me)
{
        write(@HELP
ָ���ʽ : bweapon <λ��1-50> 

HELP
        );
        return 1;
}