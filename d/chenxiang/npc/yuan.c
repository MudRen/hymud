 inherit NPC;
void create()
{
        set_name("Ԭ��ϼ", ({ "yuan zixia", "yuan"}) );
        set("gender", "Ů��" );
        set("age",22);
        set("per",50);
        set("long", "���˵��۾�����ɬ��Ц�ݣ��������ϲ�ʩ֬�ۣ�һ������ȴ������ϼ��\n");
        set("combat_exp", random(1000000)+1000000);
        set("attitude", "aggrensive");
        set_skill("move",250);
        set_skill("unarmed",60);
        set_skill("force",60);
        set_skill("dodge",250);
        set_skill("liuquan-steps",100);
        map_skill("dodge","liuquan-steps");
        map_skill("move", "liuquan-steps");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ԭ��ϼ��Ŀ��ת�����𵶣��ֶ��˶�ŷ��µ�����\n",
        "Ԭ��ϼ��Ŀһת�����������ߵ���ϼ���૵������񾩰����ҡ����ҡ���\n�Ҷ�����ô������Ӧ�������\n",
        }) );
        set("inquiry",([
        "����"  :"���������������������ѵ�������������ͷô��\n",
        "bai"  :"���������������������ѵ�������������ͷô��\n",
        "bai yujing"  :"���������������������ѵ�������������ͷô��\n",
                ]) );
        set("max_neili",500);
        set("force_factor",20);
        setup();
    carry_object("/d/chenxiang/npc/obj/purpleskirt")->wear();
}       
