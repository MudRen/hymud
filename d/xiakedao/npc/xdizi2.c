//mu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_zhou();

void create()
{
        set_name("����ʹ", ({ "xk dizi", "xk dizi" }));
        set("long", "һ�����ź��µĺ��ӡ�\n");
        set("title", "���͵�������");
        set("gender", "����");
        set("age", 75);
        set("nickname", HIB "ľ��������" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 3900);
        set("max_qi", 3900);
        set("jing", 3900);
        set("max_jing", 3900);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 170);
        set_skill("unarmed", 100);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("hand",170);
        set_skill("staff", 170);
        set_skill("taixuan-gong", 150);

set_skill("huanhe-dao", 150);
set_skill("sata-shenfa", 150);
set_skill("sumi-jian", 150);
set_skill("wuyu-quan", 150);
set_skill("xiuli-qiankun", 150);
set_skill("strike", 150);
set_skill("cuff", 150);
set_skill("unarmed", 150);
set_skill("blade", 150);
set_skill("sword", 150);
map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );

        create_family("���͵�",2, "����");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver",50);
}
