//by xiaolang
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("���ܹ�", ({ "shanliu manager" }) );
    set("gender", "����" );
    set("age", 32);
    set("force",500);
    set("title","ɽ��");
    set("force_factor",20);
    set("max_neili",500);    

    set("int", 30);
    set("long",
        "û����֪�����ܹܵ���ʵ���֣����һ�㶼�����ܹܣ�\n���������ǳ���ƽ����ͨ����ȴ�ǳ�������\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
            }) );
    
    set_skill("unarmed", 400);

    
    set("combat_exp", 35000000);
    setup();
    carry_object("/clone/misc/cloth")->wear();
//    carry_object("/d/taishan/npc/obj/hxshoes")->wear();
} 
