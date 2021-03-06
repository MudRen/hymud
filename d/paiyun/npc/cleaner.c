// cleaner.c
// by Find.

inherit NPC;

void randommove();
void do_go();
void dest_ob();

void create()
{
	set_name( "山寨仆人", ({ "paiyun servant" }) );
	set("gender", "男性" );
	set("age", random(10)+30);
	set("env/wimpy",80);
	set("str", 20);
	set("long","他是“排云寨”的仆人。\n");

	set("chat_chance", 20);
        set("chat_msg", ({
                (: do_go :),
        }) );

	set("attitude", "friendly");
	set("combat_exp", 100);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void do_go()
{
	mapping exits;
	string *dirs;
	string last_dir;

	dest_ob();

	if( last_dir = this_object()->query("last_dir"))
	{
	        if( !mapp(exits = environment()->query("exits")) ) 
		{
			destruct(this_object());
			return;
		}
	        dirs = keys(exits);

		if( member_array(last_dir, dirs) != -1)
		{
			if( domain_file(exits[last_dir]) == domain_file(query("startroom"))
			&& random(2) )
				command("go "+ last_dir);
			else	randommove();
		}
		else
			randommove();
	}
	else
		randommove();
}


void randommove()
{
        mapping exits;
        string *dirs;
	string thisdir;
	int i,n;

        if( !mapp(exits = environment()->query("exits")) ) 
	{
		destruct(this_object());
		return;
	}

	if(!query("startroom"))
	{
		destruct(this_object());
		return;
	}

	dirs = keys(exits);
	if((n = sizeof(dirs)) == 1)
	{
		command("go "+dirs[0]);
		return;
	}

	for(i=0;i<n;i++)
		if( domain_file(exits[dirs[i]]) != domain_file(query("startroom")))
			dirs[i] = 0;

	dirs -= ({0});
	if(!sizeof(dirs))
		return;
	thisdir = dirs[random(sizeof(dirs))];
	this_object()->set("last_dir",thisdir);
        command("go " + thisdir);
	return;
}

void dest_ob()
{
	object room;
	int i,m,flag = 0;
	object *inv,*guards;

	room = environment(this_object());
	if(room)
	{
	inv = all_inventory(room);

        for(i=0; i<sizeof(inv); i++)
		{
		if( userp( inv[i]) ) continue;
		if( inv[i]->query("no_shown")) continue;
		if( inv[i]->query("no_get")) continue;
		if( inv[i]->is_character()) continue;
		if( inv[i]->is_corpse()) continue;
		if( inv[i]->query_temp("guarded"))
		    {
			guards = inv[i]->query_temp("guarded");
			if(arrayp(guards))
			{
			for(m=0;m<sizeof(guards);m++)
				{
				if( guards[m] && (environment(guards[m]) == environment(inv[i])) )
					{
					if(!guards[m]->is_busy())
						flag = 1;
					}
				}
			}
		    }
		if(flag)
		    {
			flag = 0;
			continue;
		    }
		message_vision("$N捡起一"+inv[i]->query("unit")+inv[i]->name()+"。\n",this_object());
		destruct(inv[i]);
		}
	}
}
