#include <ansi.h>
inherit NPC;   
void create() 
{ 
        set_name("˫˫", ({ "shuang shuang","shuang" }) );
        set("gender", "Ů��"); 
        set("age", 19);
        set("title", "äŮ");
    set("long","�����ֱ�ϸ�������������Ǹ����ӣ������Ⱥ��ӻ�Ҫ��С�������۾��ܴ󣬵�\nȴ�����ɵ�ȫ�޹�ʣ����Ǹ�Ϲ�ӡ�����������֣��ǲ����ǳ�ª��Ҳû�в�\nȱ��ȴ����һ��׾�ӹ������������������ߣ�һ������Ť�������ε�������\n�ߡ���������������ϧΪ������һ�е����ˣ������Ǹ�������ȫ�Ļ��ζ���\n���һ��Ǹ�Ϲ�ӡ� ��\n");
    set("combat_exp", 15000);
        set("attitude", "friendly"); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear(); 
        this_object()->disable_player(" <���Բ���>");
        this_object()->set_temp("is_unconcious",1);
        set_temp("block_msg/all", 1);
       // COMBAT_D->announce(this_object(), "unconcious");
}   
