// ����� /d/city/chuzhou/npc/daughter.c
// by lala, 1997-12-17

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "�����", ({ "lin yujiao", "lin", "yujiao", }) );
    set( "gender", "Ů��" );
    set( "title", REV BBLU WHT"�����ھ�"MAG"��  ʦ"NOR );
    set( "age", 28 );
    set( "long", @LONG
�������������ͷ��Ů�������ڰ������æ����Ϊ�кܶ��Զ·������������
�����ģ���ƥû�����չܺܲ����ģ������صؿ�������������Ǯ�������á�
LONG
    );
    set( "peaceful", "friendly" );
    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 600);
    set("force",     600);
    set("force_factor", 10);
    set("combat_exp", 8000);
    set("social_exp", 80000);
    set("positive_score", 2000);
    set("negative_score", 300);

 
    setup();
      
    carry_object( "/clone/misc/cloth" )->wear(); 
    carry_object( "/clone/weapon/gangdao" )->wield();
}          
