#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;34mĞÇÔÆÏÉÅÛ[2;37;0m", ({ "wuji cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;32m´ËÎïÒÑ´ï³öÉñÈë»¯£¬µÇ·åÔì¼«£¬ÉñºõÆäÉñÖ®¾³½ç£¡Ë×ËµÍòÎï¹é×Ú£¬±ãÊÇÕâ¡°ÎŞ¼«¡±£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÊ®¶ş½ïÆßÁ½Ò»Ç®µÄ[1;32mÎŞ¼«Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;32mÄ§Íõ[2;37;0m [36mÄ¾[2;37;0m:[1;31m¿ªÔª[2;37;0m [32mË®[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[35m±ê×¼[2;37;0m 
ÌåÁé:[32m´Ö²Ú[2;37;0m °×Ê¯:[35m±ê×¼[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
³¤Éú:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞÇÒş[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÍÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "ĞÇÒş");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 52);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 43);


    set("armor_prop/armor", 590);
    set("armor_prop/defense", 37);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 74);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 41);

    set("wtypeA",0);
    set("wtypeB",13);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",3);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";