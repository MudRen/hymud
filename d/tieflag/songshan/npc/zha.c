 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��ľ��", ({ "muhe", "zha" }) );
        set("title", "��Ӱ��");
        set("gender", "����" );
        set("age", 52);
        set("agi",35);
        set("str",35);
        set("long",
                "���������ĵ�һ�쵶\n"
                );
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ľ�ϵ��������ò�������ѽ���ɺ�ѽ����\n",
//                (: random_move :),
        }) );
        set("max_neili",1000);
        set("neili", 1000);
        set("attitude", "peaceful");
 set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("per", 50);
        set("per",23);
        set("tianyu_1",1);
        set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        

         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
   setup();
        carry_object(__DIR__"obj/dafeng")->wield();
}  
int is_ghost() { return 1; } 
void die(){
        object *inv, ob;
        int i;
        inv = all_inventory(this_object());
        if (random(5)) {
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("id") == "windblade") {
                        message_vision("$N�޺޵ؿ�����һ�ۣ�һ���ְѴ�絶����ɽ�¡�\n",this_object()); 
                        destruct(ob);
                }
        }
        }
        ::die();        
}
