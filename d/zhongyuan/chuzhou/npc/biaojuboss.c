// �ھֵ�����ͷ /d/city/chuzhou/npc/biaojuboss.c
// by lala, 1997-12-13

#include <ansi.h>

inherit NPC;

inherit F_VENDOR;

void create()
{
    set_name( "��һ��", ({ "lin yiming", "lin", "master", }) );
    set( "title", REV BBLU WHT"�����ھ�"GRN"����ͷ"NOR );
    set( "gender", "����" );
    set( "age", 68 );
    set( "per", 22 );
    set( "long", @LONG
�����ھֵ�����ͷ����˵���������ӣ����ǲ�֪��ô�ģ������ھ�ȴ��Ӫ�Ĳ���
ô��������Ǻ͹ٸ��Լ������ϵĺڵ�����ؽڴ�ò����ɡ���������ү������
���ˣ��ھ�����Ҳ�����ˣ�����ֻ�ÿ��������������ӡ��ھ���ļ�����ͷ����
���Ķ���Ů������ȻҪ˵���򣬻�����ү������ˡ�
LONG
    );
    set( "attitude", "friendly" );
    set( "talk_msg",({
    "������ʲô������˵��",
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 1600);
    set("force",     1600);
    set("force_factor", 20);
    set("combat_exp", 100000);
    set("social_exp", 100000);
    set("positive_score", 5000);
    set("negative_score", 1000);


 
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
    carry_object( "/clone/weapon/gangdao")->wield();        
}          

