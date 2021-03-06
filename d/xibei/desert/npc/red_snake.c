/* red_snake.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 199804012
 */

#include <ansi.h>

inherit NPC;

void use_poison();
int check_condition( object,object );
void check_escape( object,object );
void snake_escape( object );

void create()
{   set_name( RED"巨蟒"NOR, ({ "red boa","she","snake","boa" }) );
    set( "race", "野兽");
    set( "age", 200);
    set( "long", "一条兰色的巨蟒，身上发着红光。\n" );
    set( "limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
    set( "verbs", ({ "bite" }) );
    set( "attitude", "aggressive" );

    set_temp( "apply/dodge",100 );
    set( "combat_exp", 1000000 );
    set( "dex",200 );
    set( "str",300 );
    set( "con",100 );
    set( "bellicosity", 300 );
    
    set( "max_qi",100000 );
    set( "qi",100000 );
    set( "max_jing",100000 );
    set( "jing",100000 );
    set( "chat_chance_combat", 40 );
    set( "chat_msg_combat", ({
                (: use_poison :),
        }) );
    setup();
}
void use_poison()
{
    object *enemy, ob,me;
    string msg;
    me = this_object();
    enemy = query_enemy();
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
    tell_object(ob,me->name()+RED"迅疾地冲向了你，在你的腿上咬了一下。\n"NOR);
    tell_object(ob,RED"你低头一看，发现腿上黑了一块，看来中毒了。\n"NOR);
    if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
            ob->apply_condition("snake_poison", 
            (int)this_player()->query_condition("snake_poison")
            + random(5)+10);
}



int check_condition( object me,object ob )
{
    int my_kee_ratio,my_sen_ratio;
    int his_kee_ratio,his_sen_ratio;

    my_kee_ratio = me->query( "qi" )*100/me->query( "max_qi" );
    my_sen_ratio = me->query( "jing" )*100/me->query( "max_jing" );
    his_kee_ratio = ob->query( "qi" )*100/ob->query( "max_qi" );
    his_sen_ratio = ob->query( "jing" )*100/ob->query( "max_jing" );
    if ( !me->is_fighting() ) return 0;
    if ( my_kee_ratio<10 || my_sen_ratio<10 )
        if( his_kee_ratio>20 && his_sen_ratio>20 )
            return 1;
    return 0;
}

