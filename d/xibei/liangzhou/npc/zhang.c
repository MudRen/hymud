// Npc : zhang.c ��Ա��
// hydra

#include <ansi.h>
inherit NPC;

string ask_me( object );

void create()
{
    set_name( "��Ա��", ({ "zhang yuanwai", "zhang" }) );
    set( "attribute", "friendly" );
    set( "gender", "����" );
    set( "age", 45 );
    set( "long", @LONG
��Ա��Ҳ�Ǹ������ˣ�����Ͽ�û�У������ٳּ�ҵ��������������
���ĵ���������ʱ�Ӽ����ˣ����������ݺܵ����ġ�
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );   
   
    set("inquiry",([
        "�Ϸ���"  :   (:ask_me:),
        "����"    :   (:ask_me:),
    ]) );
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

string ask_me( object ppl )
{
    ppl = this_player();
    if ( ppl -> query_temp("����/allow_enter" ))
    {
        tell_object(ppl,CYN"��Ա�����ԭ�������Ϸ��ɽ������ģ���һ��Ҫ�Ⱦ�СŮ����\n"NOR);
        ppl->set_temp("����/can_enter_gelou",1);
        return "�Ϸ�м�������ʦ�Ĵ����£�";
    }
    else
    {
        return "�����ʴ����µ��Ϸ��ɰɣ����ڸ��ڵĴ�������ס�š�";
    }
}
