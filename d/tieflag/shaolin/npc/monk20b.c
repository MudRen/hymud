 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack(); 
void create()
{
        set_name("׳�����", ({ "shaolin monk", "monk"}) );
        create_family("������", 18, "����");
        set("gender", "����" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
        set("nickname",HIG"ר��һ��"NOR);
        set("long", "���Ƕ�����ר���о������书��Ѱ���ƽ���ɾ��еĺ��У�\n");
        set("vendetta_mark","shaolin");
        set("cps",80);
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",50);
        set("max_mana",1000);
        set("mana",1000);
                  
        set_skill("unarmed",200);
        set_skill("jingang-quan",200);
        set_skill("staff", 200);
        set_skill("pudu-zhang",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("spells",100);
        set_skill("kwan-yin-spells",100); 
        map_skill("spells","kwan-yin-spells");
                
        set("resistance/kee",40);
   set("resistance/sen",50);
        set("resistance/gin",20+random(80));
        
        map_skill("staff", "pudu-zhang");
        map_skill("parry", "pudu-zhang");
        map_skill("dodge","shaolin-shenfa");
        map_skill("unarmed","jingang-quan");
        map_skill("move","shaolin-shenfa");
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                name()+"Ц�����ڶ�������Ұ��\n",
                (: smart_fight() :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"̾�������ģ���������ħ������ʽ�����Ǻ���������\n",
                name()+"Ц����Ҳ��֪�����񺯣�����ü������ڽ���
���㣡���ɽ���书һ�����в���ʮ��������\n",
                name()+"����������Ů��Ҳ������ˣ�\n",
                name()+"�е������ڱ����ҳ������ˣ�\n"
        }) );
        setup();
        carry_object(__DIR__"obj/monk20b_cloth")->wear();
        carry_object(__DIR__"obj/stick")->wield();
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
/*      for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie())
                {       who->cast_spell("zombie-bolt");
                        return;
                }               
   }*/
        who->smart_attack();
        return;
} 
smart_attack() {
        if (this_object()->query_temp("weapon"))
                this_object()->perform_action("staff.hequhecong");      
                else this_object()->perform_action("unarmed.qianshouqianbian");         
        return;
        }  
