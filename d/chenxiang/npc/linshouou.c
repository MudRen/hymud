 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu(); 
void create()
{
        set_name("���ݾ�", ({ "lin shoujuan" }) );
        set("gender", "����");
        set("age", 55);
        set("long",
"���¸߹ڣ�����һ����׺����ĳ�����ͷ����Ȼ���ѻ��ף���������
�Ƿ����ʣ�ȫ����̬������\n"
);
        set("inquiry", ([
            "�����" : (: kill_him :),
             "��ź�" : (: fanghe :),
              "������" : (: peiyu :),
   ]));
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ݾ�Ц�����������޼��ŵ���������������С����������ģ���\n",
                "���ݾ�����õط�ѽ�õط���\n",
        }) );
          
        set("attitude", "friendly");
        set("title","���ݴ��");
        set("nickname", HIG"�⻨��"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","swordsman");   
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
                
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 2);
        set("spi", 30);
        set("fle",50);
        
        set("force", 1000);
        set("max_neili",1000);
        set("force_factor", 50);
        
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
             
      	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 

        add_money("gold", random(4));
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/pozhi1");
} 
 
int kill_him()
{
        object me;
        me = this_player();
        command("say ������֪�����治�٣��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int fanghe()
{
    command( "say �ź������������޼��ŵ������ˡ�");     
    return 1;
}  
int peiyu()
{
    command ("say ��С���������ֲ��ɲĵĶ��ӡ�");
    return 1;
}   
