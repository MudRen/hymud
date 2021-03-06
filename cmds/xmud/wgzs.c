// chskill.c
// Modified by Cody May.2001


#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_type = ([
"unarmed":      "拳脚",
"claw":         "爪功","cuff":         "拳功",
"finger":       "指功","strike":       "掌功",
"hand":         "手功","leg":          "腿功",
"sword":        "剑法","blade":        "刀法",  
"dagger":       "匕法","brush":        "笔法",          
"spear":        "枪法","hook":         "钩法",          
"stick":        "棒法","staff":        "杖法",          
"club" :        "棍法","throwing":     "暗器",          
"whip":         "鞭法","axe":          "斧法",
"hammer":       "锤法","force":        "内功",  
"dodge":        "轻功","parry":        "招架",  
]);

string skill_enables(object sk);

int sort_skill(string file)
{
        int i;
        if ( !sscanf(file, "%*s.c") )  return 0;
        i = strlen(file);
        while(i--){
                if( file[i] == '.' ) continue;
                if( file[i] < 'a' || file[i] > 'z' )
                        return 0;
        }

        return 1;
}

int main(object me, string arg)
{
        string exert,str, *file;
	mapping skl;
	string *sname;
        object sk;
        int i, j , m= 0;

        seteuid(getuid());
                
       str = "";
	skl = me->query_skills();
	if(!sizeof(skl)) {
		write( "$jz#你目前并没有学会任何技能!\n");
		return 1;
	}
	sname  = sort_array( keys(skl), (: strcmp :) );
for(m=0;m<sizeof(skl);m++){

        if(member_array(sname[m], keys(valid_type))!=-1) continue;
        sk = load_object(SKILL_D(sname[m]));
        exert = skill_enables(sk);
        if(exert != ""){
                i++;
        }
        if( stringp(exert = SKILL_D(sname[m])->exert_function_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        if(j && j > 0){
                if( i )
                for(i=0; i < j; i++){
                        str += sprintf("$jz#  〖"+to_chinese(replace_string(file[i], ".c", ""))+"〗--(exert %s)\n",replace_string(file[i], ".c", ""));
                }
                j = 0;
        }
        if( stringp(exert = SKILL_D(sname[m])->perform_action_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        if(j && j > 0){
                if( i )
                for(i=0; i < j; i++){
                        str += sprintf("$jz#  〖"+to_chinese(replace_string(file[i], ".c", ""))+"〗--(perform %s)\n",replace_string(file[i], ".c", ""));
                }
                j = 0;
        }
i=0;
}
        write(str);
 write("$#\n");
        return 1;
}



string skill_enables(object sk)
{
        int i, j;
        string str, *skills;
        skills = keys(valid_type);
        
        for(i=0; i < sizeof(skills); i++) {
                if (sk->valid_enable(skills[i])) continue;
                skills[i] = 0;
        }
        
        skills -= ({ 0 });
        j = sizeof(skills);
        if( !j || j < 1)
                return "";
        str = "";
                
        for(i=0; i < j; i++) {
                str += sprintf("%-14s ", valid_type[skills[i]]+"("+skills[i]+")");
        }
        return str;
}
int help(object me)
{
        write("\n指令格式 : chskill [武功名称]\n");
        write(@HELP
这个指令可以让你查询此项技能的功能和数据。

特殊技能表示可以 enable 的技能。

内功方面显示可运用(exert)的内功。

外功方面显示可使用(perform)的外功。

妖术方面显示可运用(cast)的妖术。      
HELP);

    return 1;
}

