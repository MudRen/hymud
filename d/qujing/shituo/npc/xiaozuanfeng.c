//xiaozuanfeng.c

int ask_name(); 

inherit NPC;
#include "/d/migong/romnpc2.c"
// inherit NPC;
void create()
{
        object yaopai;

	set_name("С���", ({"xiao zuanfeng", "xiao yao", "xiaoyao", "yao"}));
	set("gender", "����" );
	set("age", 16);
        set("title", "ѲɽС��");
	set("long", "һ��С������������ͭ�������߱�ߺ�ȡ�\n");
	set("class", "yaomo");
	set("combat_exp", 5000);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 10);

	set("per", 11);
	set("max_kee", 150);




	setup();
	   initlvl((300+random(300)),random(63));
	carry_object("/d/obj/armor/shoupi")->wear();

     

       set("inquiry", ([

                   "�����"     : "�ҼҴ������ͨ��󣬱��¸�ǿ����һ������ʮ�������",
                "������"     : "�ҼҶ�����������ɣ��Բ�ü�������ۣ�"
                          +"���������ⵣ��������������������������"
                          +"ֻ��һ���Ӿ�ȥ����������ͭ��Ҳ�ͻ�����ɥ��",
                "������"     : "�Ҽ��������Ƿ���֮������Ƴ����������ֽд���������"
                          +"�ж�ʱ�������Ӻ�����ͼ�ϡ�",
         ]) );

        set("chat_msg", ({
            "С�������ͭ��ߺ�ȵ���Ѳɽ�ģ����ڵ�ע���ˣ��⼸����ɮ��Ҫ���������Ҷ�������\n",
            "С��纰������ɮ�Ĵ�ͽ������ռ������������׹���\n",
            "С��纰������ɮ�Ķ�ͽ����˽��ͷ�����������⣡\n",
            "С��纰������ɮ����ͽ��ɳ��������������������㾫��\n",
  (: random_move :),
        }) );
        set("chat_chance", 25);
}




