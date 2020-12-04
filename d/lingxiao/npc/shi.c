#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ʱ����",({"shi wannian","shi",}));
        set("gender", "����");
        set("age", 20);
        set("long", 
               "���������ǵ���������ʱ���꣬�ڴ�����������\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
         set("neili", 33000);
        set("max_neili", 33000);
        set("jing", 18000);
        set("max_jing", 18000);
        set("qi", 18000);
        set("max_qi", 18000);
        set("jiali", 100);


        set("combat_exp", 250000); 
        set("shen_type", 0);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
       "ʱ����޺�˵�����Ϸ��Ӳ�֪������ô�ˣ����Լ���������Ū�����ϳ�����\n", 
       "ʱ����ѽ�һ������Ȼ�������������⣬˭��������Ϸ��ӷų�����\n", 
        }) );
          set_skill("sword", 280);
        set_skill("force", 230);
        set_skill("parry", 230);
        set_skill("dodge", 230);
        set_skill("literate", 180);

        set_skill("xueshan-sword", 320);
        set_skill("bingxue-xinfa", 320);
        set_skill("snow-zhang", 300);
        set_skill("snowstep", 300);
        set_skill("doom-hand", 300);
        set_skill("hanshan-strike", 300);
        set_skill("snowwhip", 300);
        set_skill("hand", 250);
        set_skill("whip", 250);
         set_skill("strike", 280);
        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "dodge.snowfly" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: perform_action, "strike.zhangjian" :),
                (: perform_action, "strike.siji" :),
	               (: perform_action, "hand.hantian" :),                		
                (: exert_function, "powerup" :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("������", 6, "����");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
} 
void init()
{ 
        object ob;
        ::init();

        ob = this_player();  
      if(ob->query("family/family_name") !="������")
        {
                command("heng");
                command("say ���Ȼ�Ҵ��뱾�ɽ��أ������ɣ�\n");
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }
        else if(ob->query("family")["master_name"]=="������")
        {
                command("say ʦ������ˣ���ȥ��ʦ��ɣ�����С�ĵ㡭��û׼���ַ����ˡ�");
        } 
        else if(ob->query("family")["master_name"]=="����")
        {
                command("say ���ǰ�ʦ��ĵ��Ӱɣ����ȥ������ү�Ӱɣ����Ĳ�Խ��Խ����������");
        }
}

