 inherit NPC;
#include <ansi.h>
void smart_fight( object who); 
void create()
{
        set_name(HIR"������"NOR, ({ "hong lianhua" }) );
        set("gender", "����");
        set("age", 18);
        set("long",
"һ��Ǭ����С��ȴ������ֻ���۾���������ؤ���������Ÿ���ͣ���������Ц��\n"
);

      
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������૵�����������һ����һ������ı����ʲô�أ���\n",
        }) );
          
        set("attitude", "friendly");
        set("title","������ؤ");
        set("score", random(50000));
        set("reward_npc", 1);
        set("difficulty",20);
        set("class","beggar");
        
        set("combat_exp", 4000000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 180);
        set_skill("sword", 200);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("staff",200);
                        

        set_skill("xianglong-zhang",370);
        set_skill("unarmed",160);
        
        map_skill("unarmed","xianglong-zhang");


        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object(__DIR__"obj/bamboo_staff")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
void smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
   if (i>1) {
                who->perform_action("staff.tianxiawugou");
                return;
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) 
                if (enemy[i]->query_skill("iron-cloth")>200) {
                        if (this_object()->query_temp("weapon")){
                        command( "say ��������Ӳ������һ���ҵĽ���ʮ���ƣ�");
                        command("unwield staff");
                        who->perform_action("unarmed.xianglongwuhui");
                        }
                } else  {command("wield staff");
                        who->perform_action("staff.banzijue");  
                        }               
        }
        return;
} 
