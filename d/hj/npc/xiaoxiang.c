#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "xiaoxiang zi", "zi", "xiaoxiang" }));
        set("title", "��������");
        set("long", "����ĸ��ݣ�����Ѫɫ��������ʬ����������͸��һ���������ֳ�һ����ɥ����\n");
        set("gender", "����");
        set("rank_info/respect", "����");
        create_family("ؤ��", 15, "����");
        set("age", 43);
        set("attitude","heroism");
        set("str", 36);
        set("dex", 30);
        set("con", 33);
        set("int", 32);
        set("shen", -7000);
        set("env/wimpy", 60);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("staff", 300);
        set_skill("huagong-dafa", 320);       
        set_skill("tianshan-zhang", 320);  
        set_skill("xiaoyaoyou", 320);
        set_skill("hand", 100);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("hand", "suohou-shou");
        set("combat_exp", 5000000);
        set("max_qi", 55000);
        set("max_jing", 50000);
        set("eff_jingli", 50000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 50);
        set("inquiry", ([            
            "���ַ���" : "�ٺ٣��ҳ������Ǹ��Ϻ��еĹ�ʦ������������",
            "�����" : "���Ǹ�ç��������ʲ��",
            "������" : "���˹��򲻴���������Ľ���̫ҫ�ۣ������������ʿ��",
            "��Ħ��" : "�������ģ��ڹ��������ǣ��ٺ٣�����̫С��",            
       ]) );
       
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hushen" :),                
                (: perform_action, "unarmed.jinxian" :),                
                (: perform_action, "unarmed.tianshan" :),                
             
        }) );
       
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
            "�������۾�����б������Ǳ�΢΢��Ц��\n",
            (: random_move :),  
            "�����ӵ����������书�������ã��ѵ����ϵ�����������֮���᣿�ֵܿ��е㲻�������� ����\n", 
            (: random_move :),          
        }) );
        carry_object(__DIR__"obj/gangzhang")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();
}

void kill_ob(object me)
{     object ob=this_object();
      command("grin");
      command("say ���������ɣ�");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);            
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);            
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);            
      ::kill_ob(me);
}
