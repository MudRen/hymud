#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;36mÀ¥ÂØÖ®Åû·ç[2;37;0m", ({ "kunlun armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;36m	Ğ¦½­ºşÀË¼£Ê®ÄêÓÎ£¬¿Õ¸ºÉÙÄêÍ·¡£
	¶ÔÍ­ÍÓÏï²´£¬Ò÷ÇéÃìÃì£¬ĞÄÊÂÓÆÓÆ£¡ 
	¾ÆÁîÊ«²ĞÃÎ¶Ï£¬ÄÏ¹úÕıÇå³î¡£ 
	°Ñ½£ÆàÈ»Íû£¬ÎŞ´¦ÕĞ¹éÖÛ¡£ 
 
	Ã÷ÔÂÌìÑÄÂ·Ô¶£¬ÎÊË­Áô³şÅå£¬ÅªÓ°ÖĞÖŞ£¿
	ÊıÓ¢ĞÛ¶ùÅ®£¬¸©Ñö¹Å½ñ³î¡£
	ÄÑÏûÊÜµÆ»èÂŞÕÊ£¬Øöê¼»¨Ò»ÏÖºŞÄÑĞİ£¡
	Æ®Áã¹ß£¬½ğ¸êÌúÂí£¬Æ´Ôá»ÄÇğ£¡ 
[2;37;0mÕâÊÇÒ»¼şÓÉ¾ø¶Ô¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁù½ïÁãÁ½ÁãÇ®µÄ[1;36mÀ¥ÂØÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
×ÏÊ¯:[32m´Ö²Ú[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[35m±ê×¼[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¿Æ±È[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕĞ¼Ü[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "¿Æ±È");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 35);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 134);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 34);
    set("armor_prop/jing", 57);
    set("armor_prop/jingli", 57);
    set("armor_prop/damage", 36);

    set("wtypeA",13);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "parry",
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