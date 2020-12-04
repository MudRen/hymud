inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("万圣龙王", ({"wansheng longwang", "longwang", "long"}));
        set("long", "他是乱石山碧波潭的老龙王。\n");
        set("age", 68);
        set("attitude", "peaceful");
        set("gender", "男性");
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
        message("sound", "\n\n万圣龙王怒道：你竟敢欺人太甚！\n\n", environment());
        message("sound", "\n万圣龙王半空中一转，现了真身！竟是一条五爪金龙！\n\n", environment());
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
        message("sound", "\n\n万圣龙王怒道：你竟敢欺人太甚！\n\n", environment());
        message("sound", "\n万圣龙王半空中一转，现了真身！竟是一条五爪金龙！\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon");
                obj->move(environment(me));
                obj->kill_ob(me);
                me->fight_ob(obj);
        }

        destruct(this_object());
}

�