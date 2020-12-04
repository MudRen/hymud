#include <ansi.h>

//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
inherit F_VENDOR; 


void create()
{
        set_name("��ػ�",({"ma huihui","huihui"}));
        set("title","�����һˤ�Ӻ���");
        set("long","��ػ����������⣬�����ӡ���˵�ܽ�ţ����������ۼ������Ѽ����Ұζ����ʱ�����۵��񶹸���\n");
        
        set("gender","����");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",1000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set("combat_exp", 20000000);
        set("score", 200000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",250);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );	
                
        set("max_neili",200+random(500));
        set("neili",query("max_neili"));
        set("force_factor",300);
        
        
        set("inquiry", ([
                
        ])); 
//      set("death_msg",CYN"\n$N˵�����������ݣ������˶����Ź�����\n"NOR);    
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );  */
	set("vendor_goods", ({
                __DIR__"obj/cow1",
                __DIR__"obj/cow2",
                __DIR__"obj/cow3",
                __DIR__"obj/cow4",
	}));

                  
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
}       
void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}  