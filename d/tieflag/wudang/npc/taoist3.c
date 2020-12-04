#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("�γ���", ({ "song" }) );
        set("gender", "����");
        set("age", 30);
        set("long",
                "�γ������䵱�𹤵��ˣ����Ż�ɫ����\n"
        );
        set("combat_exp", random(10000));
        set("class", "taoist");
        set("neili", random(300));
        set("max_neili", random(300)); 
        create_family("�䵱��", 58, "����"); 
       set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
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
        setup(); 
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear(); 
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if( (string)me->query("family/family_name")!="�䵱��" ) {
                if( (string)me->name()!="����" ) {
                        say( HIY "�γ���˵������λ" + RANK_D->query_respect(me)
                                + "����������Ժ���䵱�صأ����������롣\n"NOR);
                        } 
                else {
                        message_vision( HIY "$N�������´�����$n����˵������ʦ�絽����ȥ�ˣ�\n"NOR, this_object(), me);
                        message_vision( HIY "Ϊʲô��ɫ���ã��������岻������쵽��Ժ��Ϣ��\n"NOR, this_object(), me);
                }
        }
        else {
                say( HIY "�γ���˵������λ" + RANK_D->query_respect(me)
                        + "���Ժ��Ϣ���跹�����͵���\n"NOR);
        }
} 
