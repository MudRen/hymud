#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����", ({ "wugong shen", "shen" }) );
        set("long",
         "�󣬷ǳ��󣬼�����ܹ��������Ŀ���ֻ������֣��󣡡�\n");
        set("nickname", HIC "ǧ��ǧ��"NOR); 
        set("per",2);
        set("combat_exp", 1400000);
        set("force",500);
        set("max_neili",500);
        set("no_arrest",1);
        set_temp("apply/damage",50);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/spear")->wield();
} 
void init()
{
                ::init();
                add_action("do_get","get");
} 
int do_get(string arg)
{
        string what,where;
        if(!arg) return notify_fail("������ʲô��\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "��ͷ" ))
        {
                command("say ���ý�ҩ���ȹ�������һ����˵��");
                return 1;
        }
}    
