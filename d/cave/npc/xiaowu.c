#include <ansi.h>
inherit NPC;
int gao();
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
    set_name("С��", ({"xiao wu","wu"}) );
    set("gender", "����" );
    set("nickname", HIC"���ֽ�"NOR);
    set("title", "������ �̿�");
    set("long", "С�俴���·��Ǹ�����㡢����ɢ���ˣ���ϲ��Ц����ϲ���ơ�û����������
����ɱ��ʱ�Ķ����Ƕ�ôѸ�٣���ô׼ȷ������Ҫ��Ϲ������ۣ����Ľ��;�
����������ĵط���\n");
        set("attitude", "friendly");
        set("age", 25);
        set("cor", 25);
        set("cps", 25);
        set("per", 25);
        set("combat_exp", 3000000);
        set("class","assassin");
        
        set_temp("apply/armor", 100);
        set("force", 2000);
        set("max_neili", 2000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 3);
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",80);
                        break;
                default: set("resistance/kee",30);
        }
                
        set_skill("sword", 200);
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");  
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
           "С��������ü���૵����������ȳ�������³ç�һ��أ�\n",
        }) );
        set("inquiry", ([
                "gaoli" : (: gao :),
                "gao" : (: gao :),
                "����" : (: gao :),
                "gao li" : (: gao :),
        ]));
        set("jadebox", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/windsword")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(4)); 
} 
int gao(){
        object me;
   me = this_player();
        if(query("answering")){
                return notify_fail("С���ƺ�����æ��\n");
        }
        if(me->query("combat_exp") < 1000000) {
                message_vision("$N������$nһ����������ü��������û����������������һ���غ��ˡ���\n", 
                                this_object(), me);
        } else if (me->query_temp("marks/underground_gao")) {
                message_vision("$N����һ����$n�����Ҹող��Ǹ�����ȸ��������ѵ��Ǹ����Ӳ����ã�\n",
                                this_object(), me);
        } else {
                message_vision("$NƲ��$nһ�ۣ���˼�˰��Σ�˫��ͻȻ�ų����������ˣ�������������
һ�����Ծȸ�����˫˫��һ�����ԡ�\n", this_object(), me);
                set("answering", 1);
                call_out("give_jadebox", 2, me);
        }
        return 1;
} 
void give_jadebox(object me){
        object box;
        if(!interactive(me) || environment(me) != environment(this_object())){
                return;
        }  
        message_vision("$N����Ц��Ц���ã���Ͱ����ȸ����н������������ţ���������ȸ�� 
�����������棬����ȸ����ڵ�����Ŀ�ģ�����ɱ�ˣ����Ǿ��������ԡ����� 
�����򲻵���ʱ������Ҫ������\n", this_object(), me);    
        me->set_temp("marks/underground_gao", 1);
        box = new(__DIR__"obj/jadebox");
        if(objectp(box)){
                box->move(me);
        }
        delete("answering");
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
   while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else  if (enemy[i]->is_busy()) 
                                        this_object()->smart_attack();
                          else {
                                command("enable sword lefthand-sword");
                                this_object()->perform_action("sword.duxin"); 
                                command("enable sword sharen-sword");
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    
