 inherit NPC;
//inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("�ȸ�",({"you ge","zhanggui"}));
        set("title","ɽ������");
        set("long","�����м��ջ�С��м��ջ���������и��ƹ񣬾���������ȸ��ƹ�\n");
        set("gender","����");
        set("age",33);
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("str",30);

         set("class","beggar");
         
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 1);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",180);
                        

        //set("chat_chance_combat", 1);
        set("chat_chance",1);
        set("chat_msg",({
                "�ȸ��ͷ�����ʣ�����֪�����ƹ����Ŀ������ɱ�˵���Ŀ�ˡ�\n",
                 // (: random_move :),
        }) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        //carry_object(__DIR__"obj/fanqi")->wield();  
} /*
void init()
{       
   
        add_action("do_vendor_list", "list");
} 

void reset()
{
        set("vendor_goods", ([
              "/d/fy/npc/obj/baozi1":30,
           
               "/d/fy/npc/obj/baozi2":30,
               "/d/fy/npc/obj/baozi3":30,
  "/d/guanwai/npc/obj/wineskin":30,
                "/d/xinjiang/npc/obj/baozi":30, 
        ]) );
} */