//heshang.c.����
//date:1997.8.27
//by dan 

#include <ansi.h>
inherit NPC;

int ask_for_bi();

void create()
{
    set_name(YEL"����"NOR, ({ "heshang" }) );
    set("title","������");
    set("gender", "����" );

    set("inquiry", ([
                "�����" : (: ask_for_bi :),            
    ]) );

    setup();     
}

int ask_for_bi()
{       
    object ob;
    ob = this_player();
    if ( ob->query("bellicosity") <= 100 )
    return notify_fail("��Ϲ������Щ��ʲô...?\n");
    write("�㲻Ҫɱ���ǿ�赺����ں�Ժ�ڵ���...\n");
    return 1;
}






