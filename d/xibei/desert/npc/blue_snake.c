/* blue_snake.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980412
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980412
 */

#include <ansi.h>

inherit NPC;

void use_poison();
int check_condition( object,object );
void check_escape( object,object );
void snake_escape( object );

void create()
{   set_name( BLU"����"NOR, ({ "blue boa","she","snake","boa" }) );
    set( "race", "Ұ��");
    set( "age", 200);
    set( "long", "һ����ɫ�ľ��������Ϸ������⡣\n" );
    set( "limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
    set( "verbs", ({ "bite" }) );
    set( "attitude", "aggressive" );

    set_temp( "apply/dodge",100 );
    set( "combat_exp", 1000000 );
    set( "dex",200 );
    set( "str",100 );
    set( "con",100 );
    set( "bellicosity", 300 );
    
    set( "max_qi",100000 );
    set( "qi",10000 );
    set( "max_jing",10000 );
    set( "jing",10000 );
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
    tell_object(ob,me->name()+RED"Ѹ���س������㣬���������ҧ��һ�¡�\n"NOR);
    tell_object(ob,RED"���ͷһ�����������Ϻ���һ�飬�����ж��ˡ�\n"NOR);
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
}

void check_escape( object me,object ppl )
{
    object ob;
    ob=present( "red boa",environment( me ) );
    if (!ob )
    {
        if( check_condition( me,ppl) )
        {
            snake_escape( me );
            return;
        }
    }
    else if ( ob->check_condition(ob,ppl) && check_condition(me,ppl) )
    {
        snake_escape( me );
        return;
    }
    call_out( "check_escape",3,this_object(),ppl );
}

void snake_escape( object me )
{
    object ob;
    ob=present( "blue boa",environment( me ) );
    if ( !environment( me )->query( "is_center" ) )
        return;
    write( me->name()+"�����㲻����һŤͷ��������˾��\n" );
    environment( me )->create_exit();
    destruct( me );
    if( ob ) destruct( ob );
}


