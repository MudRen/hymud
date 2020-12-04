// kill.c
#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;
#include "/quest/givegift.c"
#include "/quest/where.h"
int main(object me, string arg)
{
    int my_idle,your_idle;
    object obj,ob;
    string callname,msg;
    	 mapping target;
    	int exp,pot,score;
    	int m;
	mixed *ltime;
	string time;
	ltime = localtime(time());
	m = ltime[LT_MIN];
//return notify_fail("������˭�����书��\n"+m);
    if (!me)    return 0;



    if( !arg )
        return notify_fail("������˭�����书��\n");

    if( !me->query_temp("obj/liangong"))
    {
                tell_object(me,"������û������������\n");
                return 1;
    } 
    
	if( (int)me->query("jing") < me->query("max_jing")/10 )
{
	        return notify_fail("��ľ������ˡ�\n");
}
    
	if( (int)me->query("qi") < me->query("max_qi")/10 )
{
	        return notify_fail("����������ˡ�\n");
}


    if(!objectp(obj = present(arg, environment(me))) || !me->visible(obj))
        return notify_fail("����û������ˡ�\n");

    if( environment(me)->query("no_fight") && !obj->query_condition("killer"))
        return notify_fail("���ﲻ׼������\n");

     if( obj->query("env/no_fight") )
        return notify_fail("����˲�����������\n");
     if( obj->query_temp("no_kill") )
        return notify_fail("����˲�����������\n");

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

    if(obj==me)
        return notify_fail("���ܺ��Լ�������:P��\n");

    if(me->is_busy())
        return notify_fail("��������æ��\n");
//��սϵͳ
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("����˲�������������\n");

    if(userp(me) && userp(obj) && me->is_fighting() && obj->is_fighting()) 
    {
        return notify_fail("�����ڴ�ܰ���\n");
    }

if (userp(obj))
{
	if( (int)obj->query("jing") < obj->query("max_jing")/10 )
	        return notify_fail("�Է��ľ������ˡ�\n");
    
	if( (int)obj->query("qi") < obj->query("max_qi")/10 )
	        return notify_fail("�Է����������ˡ�\n");
}



        if( !obj->query("pubduilian") && me->query("family/family_name")  !=  obj->query("family/family_name"))
           {
                      return notify_fail("����˿�����������������\n");
                      //return 1;
            }

        if( obj->query("pubduilian") && me->query("combat_exp",1) >= 2000000)
           {
                      return notify_fail("����书�Ѿ����ܴ��������ѧ�������ˣ���\n");
                      //return 1;
            }

	if( userp(obj) && query_ip_name(obj)==query_ip_name(me) )
	return notify_fail("����˿������ܺ����������\n");

	if( m==obj->query_temp("liangongtime"))
	return notify_fail("����˲ź��������,��Ҫ��Ϣһ�ᣡ��\n");
   
msg = "$N��$n����ʦ���񣬺�$n��ʼ�����书����\n";
if (me->query_temp("obj/liangong")==8)	message_vision(msg, me, obj);

//message_vision("$N��$nһ��һʽ�Ķ�����������\n", me,obj);
//message_vision("$N��$n��һȭ����һ�ƣ���Ĵ����졣\n", me,obj);
tell_object(me,"���"+obj->query("name")+"һ��һʽ�Ķ�����������\n"NOR);
tell_object(me,"���"+obj->query("name")+"��һȭ����һ�ƣ���Ĵ����졣\n"NOR);

    if(userp(obj))
    {
         //me->start_busy(2);
if (!obj->is_busy())
         obj->start_busy(2);
    obj->add("jing",-obj->query("max_jing")/100);
obj->add("qi", -obj->query("max_qi")/100);
    }
    
me->add("jing",-me->query("max_jing")/100);
me->add("qi", -me->query("max_qi")/100);
me->add_temp("obj/liangong",-1);

if( me->query_temp("obj/liangong")<=1)
{
msg = "$N��$n����ʦ���񣬽�����$n�Ķ�����\n";
	exp = 18+random(18);


	             pot = exp*2/3;
             
             score = pot/2+1;
exp=exp/2;
if ((int)me->query("combat_exp",1) < 12000000 && !me->query("zhuanshen") && !me->query("zhuanbest")  && !me->query("guard/flag"))
{
exp=exp+18;
}


me->add_temp("mpjobn3",1);
 me->add_temp("nbjob34",1);
addnl(me,"exp",exp);
             //me->add("score",score);
if ((int)me->query("combat_exp",1) <= 6000000)
{
if (random(16)==0 && me->query_skill("unarmed",1)< 300 && me->query_skill("unarmed",1)> 1)
{
me->improve_skill("unarmed", score);
tell_object(me,"��Ļ���ȭ�����˽�����\n"NOR);
}
if (random(16)==1 && me->query_skill("dodge",1)< 300 && me->query_skill("dodge",1)> 1)
{
me->improve_skill("dodge", score);
tell_object(me,"��Ļ����Ṧ���˽�����\n"NOR);
}
if (random(16)==2 && me->query_skill("force",1)< 300 && me->query_skill("force",1)> 1)
{
me->improve_skill("force", score);
tell_object(me,"��Ļ����ڹ����˽�����\n"NOR);
}
if (random(16)==3 && me->query_skill("parry",1)< 300 && me->query_skill("parry",1)> 1)
{
me->improve_skill("parry", score);
tell_object(me,"��Ļ����м����˽�����\n"NOR);
}
if (random(16)==4 && me->query_skill("cuff",1)< 300 && me->query_skill("cuff",1)> 1)
{
me->improve_skill("cuff", score);
tell_object(me,"��Ļ���ȭ�����˽�����\n"NOR);
}
if (random(16)==5 && me->query_skill("strike",1)< 300 && me->query_skill("strike",1)> 1)
{
me->improve_skill("strike", score);
tell_object(me,"��Ļ����Ʒ����˽�����\n"NOR);
}
if (random(16)==6 && me->query_skill("finger",1)< 300 && me->query_skill("finger",1)> 1)
{
me->improve_skill("finger", score);
tell_object(me,"��Ļ���ָ�����˽�����\n"NOR);
}

if (random(16)==7 && me->query_skill("hand",1)< 300 && me->query_skill("hand",1)> 1)
{
me->improve_skill("hand", score);
tell_object(me,"��Ļ����ַ����˽�����\n"NOR);
}

}
if (me->query("family/family_name") && random(5)==0 && me->query("combat_exp",1)>300000 )
{
target = wheres[random(sizeof(wheres))];
tell_object(me,obj->query("name")+"������ ��˵��"+target["chinese"]+"������Ϊ��\n"NOR);
tell_object(me,obj->query("name")+"������ ������пտ���ȥ"+target["chinese"]+"��̽(citan)һ�¡�\n"NOR);
//message_vision"��õ���������:"+target["chinese"]+"����!", me, obj);
if (wizardp(me)) tell_object(me,"λ��:"+target["weizhi"]+"\n"NOR);
me->set_temp("dl_job_target",target["weizhi"]);
}
message_vision(msg, me, obj);
me->delete_temp("obj/liangong");
obj->set_temp("liangongtime",m);
return 1;
}

    me->start_busy(2);
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : duilian <����>
��������ָ��.���Ժͱ�����������书. 


HELP
    );
    return 1;
}
 
