 inherit NPC;
void create()
{
        set_name("�����ʦ", ({ "biaotou zhuge","biaotou"}) );
        set("gender", "����" );
        set("age", 42);
        
        set("long", "����һλ��ʨ�ھֵ���ʦ��\n");
        set("combat_exp", 3200000);
        set("attitude", "friendly");
        set("class","assassin");        
        
        set("cps",40);
        set("str",36);
        
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",90);
        
        set_skill("unarmed", 150);
        set_skill("xianglong-zhang",180);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("parry",200);
        set_skill("wuxing-dun",180);
        set_skill("move",200);
        
        map_skill("dodge","wuxing-dun");
        map_skill("unarmed","xianglong-zhang");
        map_skill("move","wuxing-dun"); 
        switch (random(3)) {
                case 0: set("resistance/kee",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/sen",30);
                }
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����ʦ���˸���Ƿ˵����˯���ˡ�\n",
        }) );
        
        setup();
        add_money("silver", 5);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        if (!random(2))
        carry_object(__DIR__"obj/hongbao"); 
}       
