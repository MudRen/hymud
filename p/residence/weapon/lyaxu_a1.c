#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m因果通三世[2;37;0m", ({ "ganjiang hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
		set("long", @LONG
[31m干将威力无比，能开天辟地，荡妖除魔！
[2;37;0m这是一副由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重二斤二两零钱的[31m干将之手套[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;31m无双[2;37;0m [36m木[2;37;0m:[1;36m完美[2;37;0m [1;35m风[2;37;0m:[1;31m无双[2;37;0m 
[1;37m雷[2;37;0m:[1;31m无双[2;37;0m [1;34m电[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天玄:[32m粗糙[2;37;0m 巧制:[33m很高[2;37;0m 
白石:[1;34m举世[2;37;0m 闪电:[1;34m举世[2;37;0m 
长生:[33m很高[2;37;0m 不老:[35m标准[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m破烂站[2;37;0m 】。和一些【 [1;32m指法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "破烂站");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",37);
    set("armor_prop/dodge", 82);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 85);


    set("armor_prop/armor", 247);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 46);
    set("armor_prop/jing", 58);
    set("armor_prop/jingli", 58);
    set("armor_prop/damage", 1116);

    set("wtypeA",0);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",12);
    set("wtypeG",12);
    set("wtypeH",8);
    set("wtypeI",5);
    set("wtypeJ",12);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 21);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";