 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack(); 
void create()
{
        set_name("��ɮ", ({ "shaolin monk", "monk"}) );
        create_family("������", 17, "����");
        set("gender", "����" );
        set("age",random(30)+ 62);
        set("nickname",HIR"��ͨ����"NOR);
        set("long", "���Ƕ�����ר���о������书��Ѱ���ƽ���ɾ��еĺ��У�\n");
        set("vendetta_mark","shaolin");
        set("combat_exp",4990000);
        set("attitude", "friendly");
        set("cor",20);
        set("cps",80);
        
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",50);
        set("mana",1200);
        set("max_mana",1200);
        
        set_skill("unarmed", 200+random(100));
        set_skill("move",200);
        set_skill("force",200);
        set_skill("dodge", 180);
        set_skill("shaolin-shenfa",160);
        set_skill("hunyuan-yiqi",140);
        set_skill("yiyang-zhi",150);
        set_skill("iron-cloth",100);
        set_skill("yijinjing",100);
        
        set_skill("spells",100);
        set_skill("cibei-dao",100); 
        map_skill("spells","cibei-dao");
           
        set("resistance/kee",50);
        set("resistance/gin",20+random(80));
        set("resistance/sen",50);
        
        map_skill("iron-cloth","yijinjing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "hunyuan-yiqi");
        map_skill("unarmed", "yiyang-zhi");
        map_skill("move","shaolin-shenfa");
        

        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"̾����������������\n",
                name()+"Ц�������뿴��������ţ�\n",
                name()+"�������㿴Ҳû���ã�����츳������\n",
                name()+"���������Ѿ���ʮ����û����¥һ���ˣ�\n"
        }) );
        setup();
        carry_object(__DIR__"obj/monk20c_cloth")->wear();
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
                this_object()->perform_action("unarmed.qiankun");               
        return;
        } 
