#include <ansi.h>
inherit NPC;
int do_jie(string arg);
void create()
{
        set_name("��ʨ��", ({ "jin shizi", "jin" }) );
        set("long",
                "��ʨ�����ڣ���ò��ª��������һֻ����ӣ�ռ�˰������ĵط�����\n�˲����ÿֲ���ֻ���ÿ�Ц��\n");
        set("chat_chance",1);
        set("chat_msg", ({
                        "��ʨ���������´������㣬���������������ߣ���Щ�����������\nû�޳���С�����ӻ��ǻؼҹԹԴ���ȥ����\n",
                                })  ); 
        set("combat_exp", 300000);
        set("max_jing",1000);
        set("max_qi",1200);
        set("max_jing",900);
        set("max_neili",800);
        set("force",1500);
                
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 
int do_jie(string arg){
        
        object ob, me, yaopai;
        me= this_player();
        
        if (arg == "gaoshi"&&  environment(this_object())->query("gaoshi")) {
                if (!ob=present("yao pai",me)) {
                        if (this_player()->query_temp("yaopai")) {
                           command("say ��������أ��������ƿ������");
                                command("say ��͢����֮�ʣ��Ҿ��ٸ��������ɡ�");
                                if (!yaopai=present("yao pai",this_object())) {
                                        yaopai = new(__DIR__"obj/yaopai");
                                        yaopai->move(this_object());
                                }
                                command("give yaopai to "+me->get_id());
                                return 1;
                        }
                                                                        
                        if( time()-(int) this_player()->query("marks/last_time_jiegaoshi") < 1200 ) {
                                command("say ��ո��Թ�û��ã��Ȼ�������ɣ�");
                        } else if(present("jia gun", environment())) {
                                command("point jia gun");
                                command("say ��Ҫ֤�����ʵ�����ͺ��������аɣ���ͬ�⣨�����������");
                                this_player()->set_temp("jiegaoshi",1);
                                this_player()->set("marks/last_time_jiegaoshi",time());
                        } else {
                                message_vision("$N��$n�����й����ڣ���Ȼ�������ɡ�\n", this_object(), this_player());
                        }
                } else if (this_player()->query_temp("yaopai")) 
                                command("say �����Ѿ���������������");        
                else 
                        command("say ������������͵���ģ�����ʵ����������Ͱ���ץ����ȥ��");
                return 1;
        
        }
        return 0;
} 
void die()
{
        object ob;
        object *enemy;
        ob = query_temp("last_damage_from");
        if(!ob) { 
                enemy = this_object()->query_enemy();
                if(sizeof(enemy))
                        ob=enemy[0];
        } else {
                if(userp(ob))   ob->set_temp("marks/killjin",1);
   }
        ::die(); 
}                                  
