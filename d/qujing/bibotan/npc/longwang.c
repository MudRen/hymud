inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("��ʥ����", ({"wansheng longwang", "longwang", "long"}));
        set("long", "������ʯɽ�̲�̶����������\n");
        set("age", 68);
        set("attitude", "peaceful");
        set("gender", "����");
	set("class", "dragon");
        set("str", 30);
        set("int", 30);
        set("per", 10);
        set("con", 30);
        set("max_qi",1000);
        set("max_jing", 1000);
        set("combat_exp", 700000);
  set("combat_exp", 1000000);

  
        setup();
        initlvl((500+random(500)),53);
        carry_object("/clone/misc/cloth")->wear();

}

void unconcious()
{
        object me,obj;   
        if( !me = query_temp("last_damage_from") )
		me= this_player(1);
        if( environment() ) {
        message("sound", "\n\n��ʥ����ŭ�����㾹������̫����\n\n", environment());
        message("sound", "\n��ʥ���������һת��������������һ����צ������\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon"); 
                obj->move(environment(me));
		obj->kill_ob(me);
		me->fight_ob(obj);
        }

        destruct(this_object());
}

void die()
{
        object me,obj;

        if( !me = query_temp("last_damage_from") )
                me= this_player(1);
        if(environment() ) {
        message("sound", "\n\n��ʥ����ŭ�����㾹������̫����\n\n", environment());
        message("sound", "\n��ʥ���������һת��������������һ����צ������\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon");
                obj->move(environment(me));
                obj->kill_ob(me);
                me->fight_ob(obj);
        }

        destruct(this_object());
}

�