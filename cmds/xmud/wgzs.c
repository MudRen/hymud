// chskill.c
// Modified by Cody May.2001


#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_type = ([
"unarmed":      "ȭ��",
"claw":         "צ��","cuff":         "ȭ��",
"finger":       "ָ��","strike":       "�ƹ�",
"hand":         "�ֹ�","leg":          "�ȹ�",
"sword":        "����","blade":        "����",  
"dagger":       "ذ��","brush":        "�ʷ�",          
"spear":        "ǹ��","hook":         "����",          
"stick":        "����","staff":        "�ȷ�",          
"club" :        "����","throwing":     "����",          
"whip":         "�޷�","axe":          "����",
"hammer":       "����","force":        "�ڹ�",  
"dodge":        "�Ṧ","parry":        "�м�",  
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
		write( "$jz#��Ŀǰ��û��ѧ���κμ���!\n");
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
                        str += sprintf("$jz#  ��"+to_chinese(replace_string(file[i], ".c", ""))+"��--(exert %s)\n",replace_string(file[i], ".c", ""));
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
                        str += sprintf("$jz#  ��"+to_chinese(replace_string(file[i], ".c", ""))+"��--(perform %s)\n",replace_string(file[i], ".c", ""));
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
        write("\nָ���ʽ : chskill [�书����]\n");
        write(@HELP
���ָ����������ѯ����ܵĹ��ܺ����ݡ�

���⼼�ܱ�ʾ���� enable �ļ��ܡ�

�ڹ�������ʾ������(exert)���ڹ���

�⹦������ʾ��ʹ��(perform)���⹦��

����������ʾ������(cast)��������      
HELP);

    return 1;
}

