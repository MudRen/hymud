// beggar.c

inherit NPC;

void create()
{
        set_name("��ؤ", ({ "beggar" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ��������˪֮ɫ������ؤ��\n");
        set("combat_exp", 2000);
        set("str", 27);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 5);
        setup();
        set("chat_chance", 20);
        set("chat_msg", ({
                "��ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                "��ؤ������ش��˸���Ƿ��\n",
		  "��ؤ����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
                (: random_move :)
        }) );
        set("inquiry",([
	"�л���" : "�ǿ���������ؤ�ľ��\n",
]));
        carry_object(__DIR__"obj/old_book");
	carry_object(__DIR__"obj/beggar_cloth")->wear();
}

int accept_object(object me, object obj)
{
	object ob;
	if(obj->name() == "����") {
	if(!me->query_temp("xiaozhen/����")) {	
		command("say �����������ٽл��������ˣ��úø���һ�£�лл�ˡ�");
		me->set_temp("xiaozhen/����",1);
	return 1;
		}
		command("say ��������һֻ������ô����˼�������ɣ�������һ�¡�");
		me->start_busy(3);
		write("��ؤ���ջ���Ū����æ����һ��\n");
		ob = new(__DIR__"obj/jiaohuaji");
		ob->move(me);
		me->delete_temp("xiaozhen/����");
		me->stop_busy();
		command("say ��ֻ�л����͸����������ʰɡ�");
		return 1;
	}
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"������С������뿪��\n");
        return 0;
}