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
	      set_name("[36mÇàË÷Ö®·ş×°[2;37;0m", ({ "qingsuo cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[36mÇàË÷Ö®·ş×°[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¾Å½ïÆßÁ½ËÄÇ®µÄ[36mÇàË÷Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;33m½ğ[2;37;0m:[33mºÜ¸ß[2;37;0m [36mÄ¾[2;37;0m:[1;33mÌìÊ¥[2;37;0m [31m»ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÄ½ÈİÃ×[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÊÖ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "hhhe");
		set("ownername", "Ä½ÈİÃ×");
		set("value", 16000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",40);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 36);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 830);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 53);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 47);
    set("armor_prop/jingli", 47);
    set("armor_prop/damage", 0);

    set("wtypeA",4);
    set("wtypeB",10);
    set("wtypeC",4);
    set("wtypeD",9);
    set("wtypeE",4);
    set("wtypeF",0);
    set("wtypeG",3);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";