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
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������૵�����������һ����һ������ı����ʲô�أ���\n",
        }) );
          
        set("attitude", "friendly");
        set("title","������ؤ");
        set("score", random(50000));
        set("reward_npc", 1);
        set("difficulty",15);
        set("class","beggar");
        
        set("combat_exp", 4000000);        
        set("int", 30);
        set("cps", 50);
        set("spi", 30);
        set("fle",50);
        set("str",40);
        
     	set("str", 60);
	set("int", 69);
	set("con", 60);
	set("dex", 68);

	set("qi", 19500);
	set("max_qi", 19500);
	set("jing", 16900);
	set("max_jing", 16900);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 150);

	set("combat_exp", 9500000);
	set("score", 200000);
set_skill("qixian-wuxingjian", 380);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 380);
set_skill("zhaosheshu", 380);
set_skill("yangsheshu", 380);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",320);
	set_skill("hand",320);
	set_skill("training",380);
	set_skill("staff", 250);
	set_skill("hamagong", 380);
	set_skill("chanchu-bufa", 380);
	set_skill("shexing-diaoshou", 380);
	set_skill("lingshe-zhangfa", 380);
	set_skill("hamashengong", 380);
	set_skill("xiyu-tiezheng", 380);
set_skill("shentuo-zhang", 380);
	map_skill("strike", "hamagong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
               (: perform_action, "strike.puji" :),                
	              (: perform_action, "strike.tui" :),                
		          (: perform_action, "strike.zhen " :),                
                (: perform_action, "hand.shewu" :),                
             
        }) );
        
        setup(); 
        add_money("gold", random(8));
        carry_object(__DIR__"obj/bamboo_staff")->wield();
        carry_object("/clone/misc/cloth")->wear();
        if (!random(10)) carry_object(__DIR__"obj/staffbook");
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
        who->perform_action("staff.banzijue");  
        return;
}   
