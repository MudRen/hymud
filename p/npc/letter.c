#include <ansi.h>
inherit ITEM;
#include "/quest/menpai/givegift.c"
void create()
{
        set_name("�ż�", ({"xin", "letter"}));
        set("long",
               "������ʹ�и�����ż����������songxin <id>���͸����ˡ�\n");
        set("unit", "��");
        set("weight", 5);
        set("no_put",1);
        set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_songxin","songxin");
}

int do_songxin(string arg)
{
int a;
object ob=this_object(),me=this_player(),who=this_player();
string targ;
int exp,pot;
	string msg;
 object obj,maxpot,badguy,fang,killern;
 int i,j,maxskill,fskill,rw;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("��Ҫ�����͸�˭��\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest_name") ) return notify_fail("�����͸�"+me->query("quest/quest_name")+"���ţ�����ô������Ҹ��أ�\n");
        if (userp(ob)) return notify_fail("��Ū�����˰ɣ�\n"); //��ҿ�������ͬ��NPC������
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"�����˵������������,�������ҵĴ��£��㻹���������ң���\n");
        }
        
        
fskill=me->query_skill("force",1);
if (fskill >=100)
{
	me->start_busy(2);
rw=random(199);
fskill=fskill/2+1;
killern=new("/quest/menpai/man");
killern->move(environment(me));
killern->initlvl(fskill);
killern->setn(rw);
tell_object(me, me->query("name")+"���ָ����и�" + killern->query("name") + "�ܿ��ɡ�\n" NOR);

}
        
        tell_object(me,"����Ž�����"+targ+"��\n" NOR );
        exp=me->query("quest/exp_bonus")+16;
        pot=me->query("quest/pot_bonus")+12;
        tell_object(me,HIW""+targ+"��ϲ������л����ʱ���Ÿ��ҡ�\n"NOR);



         addnl(me,"exp",exp);
        me->set("quest",0);
a=random(3000)+500;

if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
         addnl(who,"exp",exp);


}
                   //me->set_temp("menpaijob",0);
                   //me->delete_temp("menpaijob");
        me->add_temp("menpaijob",1);
        me->delete_temp("menpaikill");
        me->add_temp("menpaisx",1);
        me->delete("songxin");
        me->delete("quest");
        destruct(present("xin",me));
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

