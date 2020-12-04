
inherit ITEM;
int do_tear(string arg);

void init()
{
        add_action("do_tear", "tear");
}

void create()
{
        set_name("��ʮ���¾���", ({"book2"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\nһ��������ľ���,��Ƥ(binding)�ܾ��¡�\n");
                set("unit", "��");
                set("material", "paper");
        }
        setup();
}


int do_tear(string arg)
{
	object me;
	string dir;
	me = this_player();

        if( !arg || arg=="" ) return 0;

	if(arg=="book2")
	{
	message_vision("$Nһ�°Ѿ���˺�÷��顣\n", this_player());
	destruct(this_object());
	return 1;
	}

	if( sscanf(arg, "book2 %s", dir)==1 ) {
	if( dir=="binding" ) {
		if(this_object()->query("hasgot"))
		message_vision("$N����Ƥ˺��,������Ƥ�Ѿ���ȡ���ˡ�\n", this_player());
		else
		{
		message_vision("$N����Ƥ˺����������Ƥ����������\n", this_player());
		message_vision("$N�Ƚ���Ƥ�ϵĵ�ͼ����������Ȼ��������յ��ˡ�\n", this_player());
	        me->set("huanggong/haspi2", 1);
                this_object()->set("hasgot",1);  
	destruct(this_object());
        	}
	}
        else
	{
	message_vision("$Nһ�°Ѿ���˺�÷��顣\n", this_player());
	destruct(this_object());
	}
	return 1;
        }	
}

