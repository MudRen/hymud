#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a da", "a", "da" }));
        set("long", @LONG
�˱��񽣷����ױ���ؤ���Ĵ���֮�ף�����
֮��������������ֻ����������죬��������
�߰����ֱ�һ�㣬����ϵ��������š�ʮ��
��ǰ��˵����Ⱦ�ز���������ʱ���˶�����ϧ��
������������������
LONG);
        set("title", "ؤ���Ĵ���֮��");
        set("nickname", WHT "�˱���" NOR);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);        
        set("max_qi", 35800);
        set("max_jing", 35800);
        set("neili", 36200);
        set("max_neili", 36200);
        set("jiali", 250);
        set("combat_exp", 3500000);
        set("score", 500000);

       set("per", 20);
        set("str", 45);
        set("int", 45);
        set("con", 45);
        set("dex", 45);
        
        set("max_qi", 36000);
        set("max_jing", 32000);
        set("neili", 36000);
        set("max_neili", 36000);
        set("jiali", 150);
        set("combat_exp", 2000000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("literate", 200);
        set_skill("begging", 200);
        set_skill("checking", 200);
        set_skill("force", 280);
        set_skill("dodge", 260);
        set_skill("unarmed", 260);
        set_skill("parry", 280);
        set_skill("strike", 260);
        set_skill("sword", 380);
        set_skill("feiyan-zoubi", 260);
        set_skill("huntian-qigong", 280);
        set_skill("kuangfeng-jian", 380);
        set_skill("xianglong-zhang", 360);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("parry", "kuangfeng-jian");
        map_skill("sword", "kuangfeng-jian");

        prepare_skill("strike", "xianglong-zhang");

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object(__DIR__"obj/jian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
