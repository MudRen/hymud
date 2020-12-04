// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)

#include <room.h>
#include <ansi.h>
#include <combat.h>
#define TIME_TICK1 ((time()-900000000)*60)

inherit F_CLEAN_UP;

int look_room(object me, object env);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result=1;
	string str;
        if( !arg ) result = look_room(me, environment(me));
        return result;
}
int look_room(object me, object env)
{
	int i,n;
	object *inv;
	mapping exits;
	string str="",*dirs,*cdirs; 
	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}
        	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			{
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				{
				dirs[i] = 0;
				map_delete(exits, dirs[i]);
				}
			}
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 ){
				str += "$exit#" + dirs[0] + ":"+exits[dirs[0]]->query("short")+"\n";
			}
		else
			{
				str += sprintf("$exit#%s|%s:",
				implode(dirs[0..sizeof(dirs)-2], "|"), dirs[sizeof(dirs)-1]);
str += sprintf("%s|%s\n",
                implode(map_array(values(exits)[0..sizeof(exits)-2], (: $1 = $1->query("short") :)), "|"), values(exits)[sizeof(dirs)-1]->query("short"));	       	}
		}
	inv = all_inventory(env);
	i=sizeof(inv);
	while(i--) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i])) continue;
		if(inv[i]->is_character())
		{
		if (inv[i]->query("rider"))
			str +="$rw#"+inv[i]->name()+"("+inv[i]->query("id")+")" + "<"+inv[i]->query("rider") +">\n";
		else	
			str +="$rw#"+inv[i]->name()+"("+inv[i]->query("id")+")\n";
		}
		else{
		if (inv[i]->query("rider"))
			str +="$cw#"+ inv[i]->name()+"("+inv[i]->query("id")+")" + "<"+inv[i]->query("rider") +">\n";
		else	
			str +="$cw#"+ inv[i]->name()+"("+inv[i]->query("id")+")\n";
		}
		}
	write(str);
	return 1;
}
int help (object me)
{
        write(@HELP
HELP
);
        return 1;
}

