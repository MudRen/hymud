/* lingyang.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980330
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980330
 */

inherit NPC;

void create()
{
    set_name( "�߱�����",({ "ling yang","yang","oryx" }) );
    set( "long","һֻ������ɳĮ�е��������κܴ󣬱Ǹ߶����ˣ����ĽǾ���\n"
"�����ҩ�ü�ֵ��\n" );
    set( "race","Ұ��" );
    set( "age",5 );

    set( "str",30 );
    set( "dex",300 );
    set( "int",25 );
    set( "con",50 );

    set( "max_qi",500 );
    set( "max_jing",500 );

    set( "limbs",({ "ͷ��","����","ǰ��","����","β��","��" }) );
    set( "verbs",({ "hoof"}) );

    setup();
    carry_object( __DIR__"obj/lyjiao" );
}




