// Ǯׯ�ϰ� /d/city/chuzhou/npc/bankboss.c
// by lala, 1997-12-13

#include <ansi.h>
inherit NPC;
inherit F_BANKER;

void create()
{
    set_name( "���պ�", ({ "chen rihe", "chen", "boss", }) );
    set( "title", MAG"Ǯׯ"GRN"�ϰ�"NOR );
    set( "gender", "����" );
    set( "age", 58 );
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    set( "long", @LONG
���պ��Ǳ���Ǯׯ���ϰ壬���ж��ټҲ�û������˵����������������������
�������������ӡ��Ǯ���ڳ��е����۲�����ô̫�á���Ϊ��ô�����̣�����
��ÿ�����Ե������������š�
LONG
    );
    set( "attitude", "friendly" );
    set( "talk_msg",({
       "��������û��ʲô���ʵĶ���������������ˣ��ȵȿ�����",
    }));
     
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
}          

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}
