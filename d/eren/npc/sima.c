 inherit NPC;
void create()
{
        set_name("˾��С��", ({ "sima"}) );
        set("gender", "����");
        set("age", 12);
        set("long",
                "һ��ʮ�������С��������¶���������䲻����ϵĳ��졣
���������������ϣ�����Խ������(Loose)\n"
        );
        set("combat_exp",1000);
        set("loose",0);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
                
