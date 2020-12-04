//������100�����II���������䣩
// guanshi.c ����ϷԺ����
//����lywin 2000/6/21 

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();
int ask_done2();
#include "/quest/givegift.c"
mapping *changxi = ({ 
         ([ "changxi":"����","where":"city"   ]),
         ([ "changxi":"����","where":"beijing"  ]),
         ([ "changxi":"�ɶ�","where":"chengdu"]),   
         ([ "changxi":"����","where":"dali"   ]),   
         ([ "changxi":"��ɽ","where":"foshan" ]),   
         ([ "changxi":"Ȫ��","where":"quanzhou"]),   
         ([ "changxi":"����","where":"hangzhou"]),   
         ([ "changxi":"����","where":"lingzhou"]),   
         ([ "changxi":"����","where":"suzhou"]),   
                   });

mapping *changxi2 = ({ 
         ([ "changxi":"����","where":"city"   ]),
         ([ "changxi":"����","where":"beijing"  ]),
         ([ "changxi":"�ɶ�","where":"chengdu"]),   
         ([ "changxi":"����","where":"dali"   ]),   
         ([ "changxi":"��ɽ","where":"foshan" ]),   
         ([ "changxi":"Ȫ��","where":"quanzhou"]),   
         ([ "changxi":"����","where":"hangzhou"]),   
         ([ "changxi":"����","where":"lingzhou"]),   
         ([ "changxi":"����","where":"suzhou"]),   
         ([ "changxi":"����","where":"zhongzhou"]),   
         ([ "changxi":"��ɳ","where":"changsha"]),   
         ([ "changxi":"�ϲ�","where":"nanchang"]),   
         ([ "changxi":"����","where":"guizhou"]),   
         ([ "changxi":"����","where":"jinan"]),   
         ([ "changxi":"��Ҷ","where":"suiye"]),            	         	         	         	         	
         ([ "changxi":"����","where":"baling"]),   
         ([ "changxi":"�Ϸ�","where":"hefei"]),   
         ([ "changxi":"����","where":"annan"]),   
         ([ "changxi":"�����","where":"jinling"]),   
         ([ "changxi":"����","where":"yueyang"]),            	         	         	         	         	
         ([ "changxi":"��ƽ","where":"yanping"]),   
         ([ "changxi":"����","where":"gaoli"]),   
         ([ "changxi":"�Ž�","where":"jiujiang"]),   
         ([ "changxi":"�½�","where":"xinjiang"]),   
         ([ "changxi":"����","where":"xizang"]),   
         ([ "changxi":"����","where":"dingxiang"]),            	         	         	         	         	
                   });



 
 

 
 
 
mapping query_changxi2()
{
        return changxi2[random(sizeof(changxi2))];
}

mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
        set_name("����", ({"guan shi", "guan"}));
        set("gender", "����");
        set("age", 25);
        set("long", 
                "��������ϷԺ�Ĺ��¡�\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "over" : (: ask_done    :),
                "���" : (: ask_done    :),
                "����" : (: ask_done    :),
                "fail" : (: ask_done2    :),
                "ȡ��" : (: ask_done2   :),

        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")>0)
    {
                tell_object(me,"��ȥ���ݰɡ�\n");
                return 1;
    } 
    else 
    if( me->query("combat_exp")>1000000 && me->query("nbjob")!=29)
    {
                tell_object(me,"���Ѿ��������ˣ����ֹ��������������ˡ�\n");
                return 1;
    }


    if( me->query_condition("menpai_busy"))
    {
                tell_object(me,"�����Ҫ��������Ϣһ�°ɡ�\n");
                return 1;
    }


    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];

    if( me->query("combat_exp")>300000)
    {
    changxi = this_object()->query_changxi2();
    changxiwhere = changxi["where"];

    }
    message_vision(CYN"���¶�$N˵������ȥ" + changxi["changxi"] + "�Ĵ���ϱ���һ�°ɡ�\n"NOR,me); 
        me->set_temp("obj/changxi", 1);
        me->set_temp("obj/where",changxiwhere);
        ob=new(__DIR__ "daoju");
        ob->move(me);
        return 1;   
}

int ask_done()
{      
int exp;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"�����������Ҫ�����񣿡�\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"��û���������Ϊ�Լ�����ˣ���ȥ���ݰɡ�\n");
                return 1;
    }
    message_vision(CYN"���¶�$N˵�������ò�������Щ�����ɡ�\n"NOR,me); 
    exp=60+random(30);
    if( me->query("combat_exp",1)>1000000) exp=10;
    me->add_temp("nbjob28",1);
    me->delete_temp("obj");
    ob=new("/clone/money/silver");
    ob->set_amount(5+random(10));
    ob->move(me);
exp=exp;
addnl(me,"exp",exp);
me->apply_condition("menpai_busy",3);
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("���°ѳ�Ϸ�������˻�ȥ��\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}



int ask_done2()
{      
int exp;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"�����������Ҫ�����񣿡�\n");
                return 1;
    } 
    me->start_busy(3);
    me->apply_condition("menpai_busy",3);

        me->set_temp("obj/changxi", 0);
        me->set_temp("obj/where",0);
        me->delete_temp("obj/changxi");
        me->delete_temp("obj/where");

 
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("���°ѳ�Ϸ�������˻�ȥ��\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}
