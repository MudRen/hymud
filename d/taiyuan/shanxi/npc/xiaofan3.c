 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("����",({"seller","xiaofan"}));
        set("title","ɽ������");
        set("long","һ���������룬˹�ĺ�����������ˡ�\n");
        set("gender","����");
        set("age",33);
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("per",30);
	set("vendor_goods", ({
                __DIR__"obj/huafen", 
	}));
         set("class","beggar");
         
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",1);
                        
     
       // set("chat_chance_combat", 1);
        set("chat_chance",1);
        set("chat_msg",({
                //"С�����۵�������֪��֪������ӱ������������򹷵ġ���\n",
                //  (: random_move :),
        }) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/biandan")->wield();  
} 
void init()
{       
   
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 

void reset()
{
        set("vendor_goods", ([
            __DIR__"obj/huafen":10, 
                 
        ]) );
} 