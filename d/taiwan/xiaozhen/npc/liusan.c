inherit NPC;
int go_leave();
void on_board();
void arrive();
void create()
{
        set_name("����ү",({"liusan","liu"}));
        set("gender","����");
        set("combat_exp",300000);
        set("force",700);
        set("max_force",700);
        set("nickname","����");
        set("long","�����������⺣Ͽ���ߵ��˻���׬�����,����
���������Ҫ����,������������ڳ���������");
        set("inquiry",([
                 "����":"����ǰ�����˼ҵĻ�,��ׯ������ȥ,����һֻ�۾�!\n",
             ]));
        set("age",43);
              set_skill("parry",120);
              set_skill("dodge",120);
              set_skill("unarmed",120);
              setup();
              carry_object("/clone/misc/cloth")->wear();
              add_money("silver",80);
 }
