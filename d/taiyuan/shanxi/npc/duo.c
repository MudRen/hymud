inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("����", ({ "master lv", "master"}) );
        set("nickname", HIR "Ȩ������"NOR);
        set("gender", "����" );
        set("age", 31);
        set("per", 30);
        set("npc_difficulty",8);
        set("organization/����","а");
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("combat_exp",80000000);
        set("max_kee",200000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("max_force", 8000);
        set("force", 8000);
        set("force_factor", 120);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("long",
"
û���˵����ϻᷢ���������ģ����������ϴ��Ÿ���ͭ��ߡ�
���˵����Ͼʹ�����ͭ��ߣ����ǹ��¿������Եø����������졣
�����ϴ��ŵģ�ȴ�Ǽ��������廨���ۣ�������б���������䵶��
�ұ�ɫ�ĵ����ϣ�׺������������ 
\n"
        );
        create_family("�������", 2, "����"); 
        set("score", 20000);
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
        setup();
        carry_object(__DIR__"obj/xiuhuacloth")->wear();
        carry_object(__DIR__"obj/duomianju")->wear();
        carry_object(__DIR__"obj/duoblade")->wield();
} 
int accept_fight(object me)
{
	command("heng");
        command("say ��֪����ļһ���аɣ�");
        return 1;
}