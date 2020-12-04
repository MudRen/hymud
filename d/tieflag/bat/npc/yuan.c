#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("ԭ����", ({ "master yuan suiyun", "yuan suiyun","master"}));
    set("long",
        "
��Ц����������У���һ˫�۾��ȴ������˵�����Ŀ��顢��į������
֮��, �Ǹ�����������˹�ĵ����꣬�����仪������ȴ������
\n"
        );
    set("title","����ɽׯ������");
    set("nickname", HIR "������"NOR);
    set("gender", "����");
    create_family("����", 1, "����");
    set("student_title","����");
    
    set("class","bat");
    set("reward_npc", 1);
    set("difficulty", 25);
    set("fly_target",1);
    set("age", 26);
    set("int", 40);
    set("con", 20);
    set("per", 40);
    
    set("atman",1000);
    set("max_atman",1000);
    set("neili", 2000);
    set("max_neili", 2000);
    set("force_factor", 100);
    set("combat_exp", 80000000);
    set("attitude", "friendly");
    
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            (: perform_action, "dodge.huanyinqianchong" :),
            (: perform_action, "blade.shiwanshenmo" :),
            }) ); 
    set("chat_chance", 1);
    set("chat_msg", ({
        "ԭ�����ߵ��ٱߣ�һ����������ˮ������Ӵ���ָ�������
���伺�кܾ�û�й�����ö��������ˡ�\n ",
            "\n",
        }) );
        
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");

         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

    set("ranks",({"����","Са","��а","������","��ȸ��","�׻���",
                      "������","������"}));
    set("rank_nogen",1); 
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object(__DIR__"obj/hanhai")->wield();  
} 
void attempt_apprentice(object ob)
{
    if (ob->query("combat_exp") < 3000000) {
        command("say  ��ô����书����ôѧ�û��ҵĵ�����");
        return;
        }        
    if( (int) ob->query_temp("marks/murderhu") == 1 )
     {
        command("say �ܺã��ܺã���������Ҫ������������졢�����޼ɵ��˲ţ�");
        command("recruit " + ob->query("id"));
     }
     else     command("say ����û�����赶ɱ����仰 �������������µĵ�������");
}  
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bat");
        ob->add("betrayer",-1);
        if(ob->query("betrayer") < 0) ob->set("betrayer",0);
//      ob->add("score",-5000);
}
