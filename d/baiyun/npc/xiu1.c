 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("������", ({ "ma xiuzhen","ma" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIC"��Ӣ����֮"NOR );
        set("long",
"��ĺܸߣ�ϸϸ������һ˫���ۣ���Ц��ʱ��·�Ҳ�����ֱ��˵�ɱ����\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 15);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_neili", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "Ҷ�³�" : "�ߣ�ʲôһ��������������ɣ��ҿ�Ҳ������ˣ����������ʦ�������˼ң�\n�����������ó����µ�һ������ͷ��\n",
                "master ye" : "�ߣ�ʲôһ��������������ɣ��ҿ�Ҳ������ˣ����������ʦ�������˼ң�\n�����������ó����µ�һ������ͷ��\n",
                  "���Ŵ�ѩ" :" �����Ѫħͷ��ɱ����ʦ������Ӣ����Ѫ�����һ��Ҫ����\n",
                  "master ximen" : "�����Ѫħͷ��ɱ����ʦ������Ӣ����Ѫ�����һ��Ҫ����\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����������������ۣ���м�������Ƶ�Ҳ������ˡ�\n",
                }) ); 
    set_skill("persuading", 550);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 500);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 250);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) ); 
        setup(); 
        carry_object("/clone/weapon/changjian")->wield();
        add_money("gold",2);
        carry_object(__DIR__"obj/w_skirt1")->wear();
}   
