#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"

void sp_attack();
void create()
{
        string *names = ({"������ʿ"}); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "skeleton fighter","skeleton"}));
        set("long", "����һֻ��ͷ���ӡ�\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("max_qi", 20000);
        set("max_jing", 20000);
        set("neili", 25000);
        set("max_neili", 25000);
        set("max_jingli", 20000);
        set("attitude", "killer");
   
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        }) ); 
 

        set("combat_exp", 2500000);
        set("jiali", 5000);
        set("level", 20 );
       	set("death_msg",BLU"\n$Nɢ����һ�����ͷ��\n\n"NOR); 

        setup();
        initlvl(100+random(100)); 
        carry_object("/clone/weapon/changjian")->wield();
} 
void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) || 
            this_object()->is_fighting())
                return;
                
       
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
void set_from_me(object me)
{
        mapping my;

        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        set("jiali", query_skill("force") / 2);
}

void sp_attack()
{
        object *enemies, enemy;
        object weapon, ob;
        string msg;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies) == 0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        weapon = query_temp("weapon");
        if( objectp(weapon) ) weapon->unequip();
        if( objectp(ob = present("changjian", this_object())) ) {
                ob->wield();        
                msg = HIB"$N˫��ͻȻ����ǿ�ҵ����⣬��$n�������ۣ�$n�е�һ���ʹ��\nƬ�̺��âɢȥ��$n��Ȼ����$N�����г������ڵ�Ѫ��\n"
                 "$n��$Nʹ��һ��ʧ���ѾõĹŴ��������ˣ�\n"NOR;
                message_vision(msg,this_object(),enemy);
                enemy->receive_damage("qi",200+random(380));
                COMBAT_D->report_status(enemy);
                //ob->unequip();
                if( !enemy->is_busy() )
                        enemy->start_busy(1);
        }
        if( objectp(weapon) ) weapon->wield();
        return;
}

