// ��Ժ�ϰ� /d/city/chuzhou/npc/whorehouseboss.c
// by lala, 1997-12-17

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "Ѧ����", ({ "xue xiaolian", "xue", "boss", }) );
    set( "title", MAG"Ū��"YEL"�ϰ�"NOR );
    set( "gender", "Ů��" );
    set( "age", 38 );
    set( "long", @LONG
���Ů�˴��û�֦��չ�����ǻ����ܿ�����Щ���ˡ�������Ҽ�Ժ���ϰ塣��
˵������Ĺ���ԭ���в��ٶ�������Ů���ӣ����������������ġ�
LONG
    );
    set( "attitude", "friendly" );
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
    set("force_factor", 20);
    set("combat_exp", 500000);
    set("social_exp", 500000);
    set("positive_score", 200);
    set("negative_score", 3000);

 
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
}          



