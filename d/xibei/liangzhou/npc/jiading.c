// Npc : jiading.c
// hydra

#include <ansi.h>
inherit NPC;

string ask_me( object );

void create()
{
    set_name( "�Ҷ�", ({ "jia ding", "ding" }) );
    set( "attribute", "heroism" );
    set( "gender", "����" );
    set( "age", 27 );
    set( "long", @LONG
һ���Ҷ����е���ģ����ޱ����վ�����
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
    
    set( "talk_msg", ({
        "ȥȥ��һ��ȥ������\n",
        "�š��Ҷ�������üͷ��һ���������˵����ӡ�\n",
        "���ܲ��ܱ������ң�\n"
    }) );
    
    set("inquiry",([
        "С��"    :   "��������",
        "����"    :   "������������ɱ�ģ����ú�����",
        "�Ϸ���"  :   "�����ʴ����µ��Ϸ��ɰɣ����ڸ��ڵĴ�������ס�š�",
        "����"    :   "�����ʴ����µ��Ϸ��ɰɣ����ڸ��ڵĴ�������ס�š�",
    ]) );
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}


